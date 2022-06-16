def check_flag(L: list):
    return all(0 <= x <=10 for x in L) and len(L) >= 3

print('Chương trình nhập điểm toán lí hóa: ')
flag = False
while not flag:
    diem = list(map(int,input().strip().split()[:3]))
    flag = check_flag(diem)
print('đậu') if sum(diem) >= 18 else print('về Fuho')