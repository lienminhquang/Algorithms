# Minimum edit distance of two string using dynamic programing
# Overlap Obstructure
# https://www.geeksforgeeks.org/edit-distance-dp-5/

str1 = "geek"
str2 = "geak"

matrix = [[-1 for x in range(len(str2))] for y in range(len(str1))]


def ED(s1, s2, i1, i2):
    if i1 == -1 and i2 != -1:
        return 1
    if i1 != -1 and i2 == -1:
        return 1
    if i1 == -1 and i2 == -1:
        return 0

    
    if matrix[i1][i2] != -1:
#        print('HIT')
        return matrix[i1][i2]

#    print('COMPUTE')
    if s1[i1] == s2[i2]:
        matrix[i1][i2] = ED(s1, s2, i1-1, i2-1)
        return matrix[i1][i2]
    
    matrix[i1][i2] = 1 + min(
        ED(s1, s2, i1, i2-1), #insert
        ED(s1, s2, i1-1, i2), #remove
        ED(s1, s2, i1-1, i2-1)#replace
    )
    return matrix[i1][i2]

print(ED(str1, str2, len(str1)-1, len(str2)-1))

for x in range(len(str1)):
    print(matrix[x])
