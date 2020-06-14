
# Min cost path
# https://www.geeksforgeeks.org/min-cost-path-dp-6/?ref=lbp
# 06/14/2020

matrix = [
    [1, 2, 3],
    [4, 8, 2],
    [1, 5, 3]
    ]

cost = [[-1 for i in range(len(matrix[0]))] for j in range(len(matrix))]

print(matrix)
print(cost)
global compute_count
compute_count = 0
hit = 0

def MinCostPath(i, j, i_dest, j_dest):
    global compute_count
    global hit
    
    compute_count += 1
    if i >= len(matrix) or j >= len(matrix[0]):
        return 9999
    
    if cost[i][j] != -1:
        hit += 1
        return cost[i][j]

    if i == i_dest and j == j_dest:
        cost[i_dest][j_dest] = matrix[i_dest][j_dest]
        return matrix[i_dest][j_dest]

    down = MinCostPath(i + 1, j, i_dest, j_dest)
    right = MinCostPath(i, j + 1, i_dest, j_dest)
    diagonal = MinCostPath(i + 1, j + 1, i_dest, j_dest)
    
    cost[i][j] = matrix[i][j] + min (down, right, diagonal)
    return cost[i][j]

def PrintMinCostPath(i, j, i_dest, j_dest):
    print('(' + str(i) + ',' + str(j) + ')')

    if i == i_dest and j == j_dest:
       return
    
    min_cost = 9999
    min_node = 0
    
    if i + 1 < len(matrix):
        min_cost = cost[i + 1][j]
        min_node = [i + 1, j]

    if j + 1 < len(matrix[0]) and  min_cost > cost[i][j + 1]:
        min_cost = cost[i][ j + 1]
        min_node = [i , j + 1]
    if i + 1 < len(matrix) and j + 1 < len(matrix[0]) and min_cost > cost[i + 1][j + 1]:
        min_cost = cost[i + 1][j + 1]
        min_node = [i + 1, j + 1]

    PrintMinCostPath(min_node[0], min_node[1], i_dest, j_dest)

print(MinCostPath(0, 0, 2, 2))
print('count = ' + str(compute_count))
print('hit = ' + str(hit))

PrintMinCostPath(0, 0, 2, 2)

for i in range(len(cost)):
    print(cost[i])
