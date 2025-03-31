import heapq

# Are they the same picture?

# Defining the grid with terrain types
terrain_grid = [
    ['S', 'R', 'R', 'R', 'B', 'W', 'R', 'H', 'H', 'H'],
    ['R', 'B', 'B', 'R', 'H', 'H', 'R', 'R', 'B', 'H'],
    ['R', 'P', 'P', 'R', 'B', 'R', 'R', 'R', 'B', 'R'],
    ['R', 'R', 'R', 'R', 'W', 'R', 'P', 'P', 'R', 'R'],
    ['R', 'R', 'B', 'R', 'R', 'R', 'H', 'H', 'R', 'B'],
    ['B', 'W', 'R', 'P', 'P', 'R', 'B', 'R', 'R', 'R'],
    ['P', 'P', 'R', 'R', 'R', 'R', 'R', 'R', 'B', 'B'],
    ['R', 'B', 'R', 'R', 'R', 'W', 'H', 'H', 'R', 'R'],
    ['R', 'R', 'R', 'R', 'B', 'R', 'R', 'R', 'B', 'R'],
    ['H', 'H', 'H', 'B', 'B', 'R', 'R', 'G', 'R', 'R']
]

# Define the cost of each terrain type
terrain_cost = {
    'S': 0,    # Start
    'G': 0,    # Goal
    'R': 1,    # Regular Road
    'H': 0.5,  # Highway
    'P': 2,    # Park
    'B': float('inf'),  # Building (impassable)
    'W': float('inf')   # Water (impassable)
}

# Define the grid dimensions
start = (0, 0)  # Starting point (S)
goal = (9, 7)   # Goal point (G)

# Function to calculate Manhattan Distance divided by 2 (heuristic)
def manhattan_heuristic(x, y, goal_x, goal_y):
    return (abs(x - goal_x) + abs(y - goal_y)) / 2

# Define A* algorithm
def a_star(grid, start, goal, terrain_cost):
    rows, cols = len(grid), len(grid[0])
    fringe = []
    heapq.heappush(fringe, (0, start))
    came_from = {start: None}
    cost_so_far = {start: 0}
    expanded_nodes = []
    fringe_order = []

    while fringe:
        current_priority, current = heapq.heappop(fringe)
        fringe_order.append(current)

        if current == goal:
            break

        expanded_nodes.append(current)
        x, y = current

        # Neighbor directions (up, down, left, right)
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy

            if 0 <= nx < rows and 0 <= ny < cols:
                terrain_type = grid[nx][ny]
                if terrain_cost[terrain_type] == float('inf'):
                    continue  # impassable terrain

                new_cost = cost_so_far[current] + terrain_cost[terrain_type]
                if (nx, ny) not in cost_so_far or new_cost < cost_so_far[(nx, ny)]:
                    cost_so_far[(nx, ny)] = new_cost
                    priority = new_cost + manhattan_heuristic(nx, ny, goal[0], goal[1])
                    heapq.heappush(fringe, (priority, (nx, ny)))
                    came_from[(nx, ny)] = current

    # Total cost to reach the goal
    total_cost = cost_so_far.get(goal, float('inf'))

    return total_cost, expanded_nodes, fringe_order

# Running the A* algorithm on the grid
total_cost, expanded_nodes, fringe_order = a_star(terrain_grid, start, goal, terrain_cost)

total_cost, len(expanded_nodes), fringe_order

# Print the results
print("Total Cost of Optimal Path:", total_cost)
print("Number of Nodes Expanded:", len(expanded_nodes))
print("Order of Nodes Removed from Fringe:", fringe_order)