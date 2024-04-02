-- test.adb

with Ada_Lib; use Ada_Lib;
with Ada.Text_IO; use Ada.Text_IO;

procedure Test is
   -- testing functions for calculating factorial
   N : Positive := 5;
   A : Natural := 12;
   B : Natural := 18;
   Eq_A : Integer := 3;
   Eq_B : Integer := 7;
   Eq_C : Integer := 8;
   Solution_L, Solution_R : Diophantine_Solution;
begin
   Put_Line("loop:      " & N'Image & "! =" & Factorial_L(N)'Image);
   Put_Line("recursion: " & N'Image & "! =" & Factorial_R(N)'Image);

   Put_Line("-----------------------------------------------------------------");

-- testing functions for calculating greatest common divisor

   Put_Line("loop:      GCD(" & A'Image & "," & B'Image & ") =" & GCD_L(A, B)'Image);
   Put_Line("recursion: GCD(" & A'Image & "," & B'Image & ") =" & GCD_R(A, B)'Image);

   Put_Line("-----------------------------------------------------------------");

-- Testing functions for solving linear Diophantine equations
   Solution_L := Diophantine_Eq_L(Eq_A, Eq_B, Eq_C);
   Solution_R := Diophantine_Eq_R(Eq_A, Eq_B, Eq_C);
   Put_Line("loop:      Solution: " & Eq_A'Image & "x +" & Eq_B'Image & "y =" & Eq_C'Image & ":     x =" &
      Solution_L.X'Image & " +" & Solution_L.XK'Image & "k, y = " & Solution_L.Y'Image & " + " & Solution_L.YK'Image & "k");
   Put_Line("recursion: Solution: " & Eq_A'Image & "x +" & Eq_B'Image & "y =" & Eq_C'Image & ":     x =" &
      Solution_R.X'Image & " +" & Solution_R.XK'Image & "k, y = " & Solution_R.Y'Image & " + " & Solution_R.YK'Image & "k");

end Test;