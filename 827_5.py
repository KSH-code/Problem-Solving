import datetime
import math

N = int(input())
if N == 0:
    print("0")
else:
    arr = []
    for i in range(N):
        arr.append(input())
    pi = []
    for i in range(N):
        format = '%Y/%m/%d %H:%M:%S'
        dt_datetime = datetime.datetime.strptime(arr[i][0:-3],format)
        power = (datetime.datetime.strptime(arr[-1][0:-3],format) - dt_datetime).total_seconds()/(3600*24*365.0)
        tr = max(math.pow(0.5,power), math.pow(0.9,N-i-1))
        pi.append(tr)
    result = 0
    for i in range(N):
        result += pi[i] * int(arr[i][-2:])
    print(round(result/sum(pi)))
