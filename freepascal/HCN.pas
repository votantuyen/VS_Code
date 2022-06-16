program VD_thutuc2;
uses crt;
var a, b, c: integer;
procedure Ve_HCN (chdai, chrong: integer);
    var i, j: integer;
    begin
        for i := 1 to chdai do write('*');
        writeln;
        for j := 1 to chrong-2 do {vẽ hai cạnh bên}
        begin
            write('*');
            for i := 1 to chdai do write(' ');
            writeln('*');
        end;
        {vẽ cạnh dưới}
        for i := 1 to chdai do write('*');
        writeln;
    end;
begin {chương trình chính}
    clrscr;
    Ve_HCN(25,10);              {Vẽ hình chữ nhật kích thước 20x10}
    writeln; writeln;
    Ve_HCN(5,10);
    readln;
    clrscr;
    a:=4; b:=2;
    for c := 1 to 4 do
    begin
        Ve_HCN(a,b);
        readln; clrscr;
        a:=a*2; b:=b*2;
    end;
    readln;        
end.