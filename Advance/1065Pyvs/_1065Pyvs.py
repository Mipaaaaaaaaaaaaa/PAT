
n = input()
for i in range(int(n)):
    a = input()
    a = a.split()
    print("Case #"+str(i+1)+":",str(int(a[0])+int(a[1])>int(a[2])).lower())
