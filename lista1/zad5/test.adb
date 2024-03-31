with Ada.Text_IO;
with Interfaces.C;
with Zad_5;

procedure test is
	use Ada.Text_IO;
	use Zad_5;

    N : Interfaces.C.unsigned := 5;
    A : Interfaces.C.int := 12;
    B : Interfaces.C.int := 18;
    Eq_A : Interfaces.C.int := 3;
    Eq_B : Interfaces.C.int := 7;
    Eq_C : Interfaces.C.int := 8;

    Solution_L, Solution_R : Diophantine_Solution;
begin
    Put_Line("loop:      " & N'Image & "! = " & Interfaces.C.unsigned_long'Image(wrapped_factorial_l(N)));
    Put_Line("recursion: " & N'Image & "! = " & Interfaces.C.unsigned_long'Image(wrapped_factorial_r(N)));

    Put_Line("loop:      GCD(" & A'Image & ", " & B'Image & ") = " & Interfaces.C.int'Image(wrapped_GCD_l(A,B)));
    Put_Line("recursion: GCD(" & A'Image & ", " & B'Image & ") = " & Interfaces.C.int'Image(wrapped_GCD_r(A,B)));

    Solution_L := wrapped_diophantine_eq_l(Eq_A, Eq_B, Eq_C);
    Solution_R := wrapped_diophantine_eq_r(Eq_A, Eq_B, Eq_C);
    Put_Line("loop:      Solution: " & Eq_A'Image & "x + " & Eq_B'Image & "y = " & Eq_C'Image & ":     x = " &
        Interfaces.C.int'Image(Solution_L.X) & " + " & Interfaces.C.int'Image(Solution_L.XK) & "k, y = " & Interfaces.C.int'Image(Solution_L.Y) & " + " & Interfaces.C.int'Image(Solution_L.YK) & "k");
    Put_Line("recursion: Solution: " & Eq_A'Image & "x + " & Eq_B'Image & "y = " & Eq_C'Image & ":     x = " &
        Interfaces.C.int'Image(Solution_R.X) & " + " & Interfaces.C.int'Image(Solution_R.XK) & "k, y = " & Interfaces.C.int'Image(Solution_R.Y) & " + " & Interfaces.C.int'Image(Solution_R.YK) & "k");

end test;