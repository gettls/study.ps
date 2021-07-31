sentence = input()
cnt = 0
cro_lst = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

for i in range(len(cro_lst)):
    cnt += sentence.count(cro_lst[i])

print(len(sentence) - cnt)
