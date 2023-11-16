// Header file for module ADTMap.c
#pragma once
#include "common_types.h"

typedef struct map* Map;

// Creates and returns a map, the elements of which are compared base on the 
// compare function entered by the user.
Map map_create(CompareFunc compare, DestroyFunc destroy_key, DestroyFunc destroy_value);

// Returns the number of elements that the map contains.
int map_size(Map map);

// Inserts the key key with value value. If the same key exists, it gets replaced by the new key
// and its new value.
void map_insert(Map map, Pointer key, Pointer value);

// Deletes the key key and its value. Returns true if said key was found or false if it was not.
bool map_remove(Map map, Pointer key);

// Returns the value of the key key.
Pointer map_find(Map map, Pointer key);

// Sets new destroy functions for key and value and returns the old one.
DestroyFunc map_set_destroy_key(Map map, DestroyFunc destroy_key);
DestroyFunc map_set_destroy_value(Map map, DestroyFunc destroy_value);

// Frees all the memory that has been dynamically allocated for the map.
void map_destroy(Map map);

// Extra functions for going through the Map with Nodes
// The traversal happens in no particular order
#define MAP_EOF (MapNode)0
typedef struct map_node* MapNode;

// Returns the first node of the map.
MapNode map_first(Map map);
// Returns the node after the node given.
MapNode map_next(Map map, MapNode node);
// Returns the key of node given.
Pointer map_node_key(Map map, MapNode node);
// Returns the value of node given.
Pointer map_node_value(Map map, MapNode node);
// Returns the node that has key as its key.
// Returns MAP_EOF is such a node doesn't exit.
MapNode map_find_node(Map map, Pointer key);