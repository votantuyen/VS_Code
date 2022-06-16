a=int(input("diem toan: "))
while not (0<a<10):
    a=int(input("nhap lai diem toan: "))
b=int(input("diem ly: "))
while not (0<b<10):
    b=int(input("nhap lai diem ly: "))
c=int(input("diem hoa: "))
while not (0<c<10):
    c=int(input("nhap lai diem hoa: "))
if a+b+c>=18:
    print("dau")
else:
    print("rot")