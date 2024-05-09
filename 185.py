from scipy.optimize import linprog

d = {'5616185650518293' : 2, '3847439647293047' : 1, '5855462940810587' : 3, '9742855507068353' : 3, '4296849643607543' : 3, '3174248439465858' : 1, '4513559094146117' : 2, '7890971548908067' : 3, '8157356344118483' : 1, '2615250744386899' : 2, '8690095851526254' : 3, '6375711915077050' : 1, '6913859173121360' : 1, '6442889055042768' : 2, '2321386104303845' : 0, '2326509471271448' : 2, '5251583379644322' : 2, '1748270476758276' : 3, '4895722652190306' : 1, '3041631117224635' : 3, '1841236454324589' : 3, '2659862637316867' : 2}

A=[[int(i>=j*10 and i<(j+1)*10) for i in range(160)] for j in range(16)]
b=[1]*16

for s,bi in d.items():
    b.append(bi)
    a=[0]*160
    for i,j in enumerate(s):
        a[i*10+ord(j)-ord('0')]=1
    A.append(a)

x = linprog([0]*160,A_eq=A,b_eq=b,bounds=[[0,1]]*160,integrality=[1]*160).x

for i,j in enumerate(x):
    if(j>1-1e-9):
        print(i%10,end='')

# output: 4640261571849533
