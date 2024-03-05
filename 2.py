class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash_function(self, key):
        return hash(key) % self.size
    
    def insert_linear_probing(self, key, value):
        index = self.hash_function(key)
        if self.table[index] is None:
            self.table[index] = (key, value)
        else:
            i = 1
            while self.table[(index + i) % self.size] is not None:
                i += 1
            self.table[(index + i) % self.size] = (key, value)

    def delete(self, key):
        hashvalue = self.hashfunction(key, len(self.slots))
        flag = False
        check = 0
        while check != 1:
            if self.slots[hashvalue] == key:
                self.slots[hashvalue] = None
                self.data[hashvalue] = None
                self.indices[hashvalue] = -1
                check = 1
                flag = True
                break
            else:
                if self.indices[hashvalue] != -1:
                    oldhash = hashvalue
                    hashvalue = self.indices[hashvalue]
                    self.indices[oldhash] = -1
                else:
                    check = 1
                    break
                
    def search(self, key):
        index = self.hash_function(key)
        if self.table[index] is not None:
            for pair in self.table[index]:
                if pair[0] == key:
                    return pair[1]
        return None
    
    def print_table(self):
        for i, entry in enumerate(self.table):
            print(f"Index {i}: {entry}")


hash_table_linear_probing = HashTable(size=10)


print("Linear Probing Hash Table:")
hash_table_linear_probing.print_table()

key=[]
value=[]
a=int(input("enter how many record want to add:"))
for i in range(a):
		vk=input("enter mn")
		key.append(vk)
for i in range(a):
		sk=input("enter name")
		value.append(sk)
for i in range(a):
	for j in range(a):
		if(i==j):
			hash_table_linear_probing.insert_linear_probing(key[i],value[j])


print("\nLinear Probing Hash Table:")
hash_table_linear_probing.print_table()

vk=hash_table_linear_probing.search(252525)

print(vk)