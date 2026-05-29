INF=9999
d=[
    [0,8,INF,1],
    [INF,0,1,INF],
    [4,INF,0,INF],
    [INF,2,9, 0]

]
n=len(d)

for k in range (n):
    for i in range (n):
        for j in range (n):
            d[i][j]=min(d[i][j], d[i][k]+d[k][j])


for row in d:
    print(row)