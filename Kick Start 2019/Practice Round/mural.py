def simple_beauty(mural):
    mural_size_to_check = int((len(mural)+1)/2)
    lst = []
    for i in range(mural_size_to_check):
        lst.append(sum(mural[i:i+mural_size_to_check]))
    return max(lst)

def complex_beauty():
    mural_size = int(input())
    mural = [int(num) for num in str(input())]
    mural_size_to_check = int((len(mural)+1)/2)
    temp = 0 if len(mural)%2 else 1
    lst = []
    lst.append(sum(mural[:mural_size_to_check]))
    for i in range(1,mural_size_to_check+temp):
        lst.append(lst[i-1]-mural[i-1]+mural[i+mural_size_to_check-1])
    return max(lst)

#nb=+NB
if __name__ == "__main__":
    t = int(input())
    for i in range(1,t+1):
        #print("Case #{}: {}".format(i,simple_beauty(mural))) //failed submission
        print("Case #{}: {}".format(i,complex_beauty()))
