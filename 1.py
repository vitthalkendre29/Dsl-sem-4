s1=[]
s2=[]

def ina(s):
    a=int(input("enter how many no to be add"))
    for i in range(a):
        vk=int(input("enter a number"))
        s.append(vk)
def display(s):
    print(s)

def remove():
    val=int(input("enter a number to be removed"))
    print("removing element from s1")
    if val in s1:
        s1.remove(val)
    print("removing element from s2")
    if val in s2:    
        s2.remove(val)

def add(s):
    kk=int(input("enter index valude where element add"))
    val=int(input("enter a number to be added"))
    s.insert(kk,val)

def union(a,b):
    vk=[]
    for i in a:
        vk.append(i)
    for i in b:
        if i not in vk:
            vk.append(i)
    print(vk)

def intersection():
    




# ina(s1)
# ina(s2)
# display(s1)
# display(s2)
# remove()
# add(s1)
# add(s2)
# union(s1,s2)



