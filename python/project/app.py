# ----- CONFIGURE YOUR EDITOR TO USE 4 SPACES PER TAB ----- #
import sys,os
sys.path.append(os.path.join(os.path.split(os.path.abspath(__file__))[0], 'lib'))
import pymysql

def connection():
    ''' User this function to create your connections '''    
    con = pymysql.connect(host='tesla3.di.uoa.gr', port=3306, user='actor', passwd='Mov!es24', db='movies') #update with your settings
    
    return con

def updateRank(rank1, rank2, movieTitle):

    # Create a new connection
    con=connection()

    # Create a cursor on the connection
    cur=con.cursor()
    
    # Check for constraints
    sql = "SELECT * FROM movie WHERE title = %s" 
    cur.execute(sql, (movieTitle,))
    res = cur.fetchall()
    if(len(res) != 1): # we only want 1 row to be returned 
        return [("status",),("error",),]

    try:
        rank1 = float(rank1)
    except ValueError:
        return [("status",),("error",),]
    try:
        rank2 = float(rank2)
    except ValueError:
        return [("status",),("error",),]
    
    inputcheck = rank1 <= 10 and rank1 >= 0 and rank2 <=10 and rank2 >=0
    if(inputcheck == False):
        return [("status",),("error",),]
    
    # Update
    if(res[0][3] == None):
        sql = " UPDATE movie SET movie.rank = (%s + %s) / 2 WHERE title = %s "
    else:
        sql = " UPDATE movie SET movie.rank = (movie.rank + %s + %s) / 3 WHERE title = %s " 
        
       
    # Execute and Commit, if possible
    try:
        cur.execute(sql,(rank1,rank2,movieTitle))
    except:
        con.rollback()
        return [("status",),("error",),] # error in executing
        
    con.commit()
    

    return [("status",),("ok",),]


def colleaguesOfColleagues(actorId1, actorId2):

    # Create a new connection
    con=connection()

    # Create a cursor on the connection
    cur=con.cursor()
    # lathos gia 1 tainia exei permutations ton ithopion
    sql = '''SELECT m.title, r1.actor_id, r2.actor_id
             FROM role r1, role r2, movie m
             WHERE r1.movie_id = r2.movie_id AND m.movie_id = r1.movie_id AND r1.actor_id != r2.actor_id 
             AND r1.actor_id != %s AND r1.actor_id != %s AND r2.actor_id != %s AND r2.actor_id != %s AND
             r1.actor_id IN (
                SELECT r4.actor_id FROM role r4 WHERE r4.movie_id IN(
                    SELECT movie_id FROM role  WHERE actor_id = %s  
                )
             ) AND
             r2.actor_id IN (
                SELECT r4.actor_id FROM role r4 WHERE r4.movie_id IN(
                    SELECT movie_id FROM role  WHERE actor_id = %s
                )
             )'''
    
    cur.execute(sql,(actorId1,actorId2,actorId1,actorId2,actorId1,actorId2))
    res = cur.fetchall()

    lst = list(res)
    print(lst)

    print (actorId1, actorId2)

    return [("movieTitle", "colleagueOfActor1", "colleagueOfActor2", "actor1","actor2",),]

def actorPairs(actorId):

    # Create a new connection
    con=connection()
  
    # Create a cursor on the connection
    cur=con.cursor()

    try:
        actorId = int(actorId)
    except ValueError:
        return [("status",),("error",),]

    sql = '''SELECT DISTINCT r.actor_id
             FROM role r
             WHERE NOT EXISTS(
               (SELECT DISTINCT mg2.genre_id
                FROM role r2, movie_has_genre mg2
                WHERE r2.movie_id = mg2.movie_id AND r2.actor_id = r.actor_id AND %s NOT IN (SELECT r3.actor_id FROM role r3 WHERE r3.movie_id = r2.movie_id))
                INTERSECT
                (SELECT DISTINCT mg4.genre_id
                 FROM role r4, movie_has_genre mg4
                 WHERE r4.movie_id = mg4.movie_id AND r4.actor_id = %s AND r.actor_id NOT IN (SELECT r3.actor_id FROM role r3 WHERE r3.movie_id = r4.movie_id))
             )
             INTERSECT
             SELECT r.actor_id
             FROM role r, movie_has_genre mg
             WHERE r.movie_id = mg.movie_id AND r.actor_id != %s AND %s IN(
               SELECT r2.actor_id
               FROM role r2
               WHERE r2.movie_id = r.movie_id
             )
             GROUP BY r.actor_id
             HAVING count(distinct mg.genre_id) >= 7;'''

    cur.execute(sql,(actorId,actorId,actorId,actorId))
    res = cur.fetchall()

    lst = list(res)  # result list
    lst.insert(0,("actorId",))
    
    return lst

def selectTopNactors(n):

    # Create a new connection
    con=connection()

    # Create a cursor on the connection
    cur=con.cursor()

    sql = '''SELECT g.genre_name, r.actor_id, count(*)
             FROM movie_has_genre mg, role r, genre g
             WHERE mg.movie_id = r.movie_id AND g.genre_id = mg.genre_id
             GROUP BY g.genre_name, r.actor_id
             ORDER BY g.genre_name'''

    cur.execute(sql)
    res = cur.fetchall()

    
    cut = [] # keeps indexes in res where genre changes
    lst = [] # return list
    genre = res[0][0] # first genre
    for i in range(len(res)):
        if(res[i][0] != genre):
            cut.append(i)
            genre = res[i][0]
    cut.append(len(res)-1) # insert last cut
    start_range = 0
    for i in range(len(cut)):
        temp_lst =  sorted(res[start_range:cut[i]], key = sort, reverse = True) # sort actors in genre 
        temp_dict = {}
        for t in temp_lst:  # keep a strictly decending order (a_i > a_j, i < j) (no duplicates in number of movies)
            if t[2] not in temp_dict:
                temp_dict[t[2]] = t
        # add to the result list
        temp_lst = list(temp_dict.values())
        lst = lst + temp_lst[:int(n)]
        start_range = cut[i]

    lst.insert(0,("genreName", "actorId", "numberOfMovies")) # insert header
    return lst
    

def traceActorInfluence(actorId):
    # Create a new connection
    con=connection()

    # Create a cursor on the connection
    cur=con.cursor()


    return [("influencedActorId",),]

# sort  by the 3rd element of a tuple (movies of actor)
def sort(tuple):
    return tuple[2]

colleaguesOfColleagues(376249,22591)