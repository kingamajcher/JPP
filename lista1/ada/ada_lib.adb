-- ada_lib.adb
-- Body file

with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Text_IO; use Ada.Text_IO;

package body Ada_Lib is

   function Factorial_L(N : Positive) return Natural is
      Result : Natural := 1;
   begin
      for I in 1 .. N loop
         Result := Result * I;
      end loop;
      return Result;
   end Factorial_L;

   function Factorial_R(N : Positive) return Natural is
   begin
      if N = 0 or else N = 1 then
         return 1;
      else
         return N * Factorial_R(N - 1);
      end if;
   end Factorial_R;

   function GCD_L(A, B : Natural) return Natural is
    Temp : Natural := 0;
    TempA : Natural := A;
    TempB : Natural := B;
    begin
      while TempB /= 0 loop
         Temp := TempB;
         TempB := TempA mod TempB;
         TempA := Temp;
      end loop;
      return TempA;
    end GCD_L;


   function GCD_R(A, B : Natural) return Natural is
    TempA : Natural := A;
    TempB : Natural := B;
   begin
      if TempB = 0 then
         return TempA;
      else
         return GCD_R(TempB, TempA mod TempB);
      end if;
   end GCD_R;

   function GCD_Extended(A, B : Natural; X, Y : out Integer) return Natural is
   TempA : Natural := A;
   TempB : Natural := B;
   begin
      if TempA = 0 then
         X := 0;
         Y := 1;
         return TempB;
      else
         declare
            X0, Y0 : Integer;
         begin
            declare
               GCD : constant Natural := GCD_Extended(TempB mod TempA, TempA, X0, Y0);
            begin
               X := Y0 - (TempB / TempA) * X0;
               Y := X0;
               return GCD;
            end;
         end;
      end if;
   end GCD_Extended;

   procedure Diophantine_Format(X, Y, XK, YK : in out Integer) is
      N : Integer := 0;
   begin
      while X > 0 loop
         X := X - XK;
         N := N - 1;
      end loop;
      while X < 0 loop
         X := X + XK;
         N := N + 1;
      end loop;
      Y := Y + N*YK;
   end Diophantine_Format;

   function Diophantine_Eq_L(A, B, C : Integer) return Diophantine_Solution is
      Solution : Diophantine_Solution;
      GCD : Natural;
   begin
      Solution.X := 0;
      Solution.Y := 0;
      Solution.XK := 0;
      Solution.YK := 0;

      -- checking whether solution exists using Bezout's identity, if not then returning x = 0 and y = 0
      GCD := GCD_L(Abs(A), Abs(B));
      if C mod GCD /= 0 then
         return Solution;
      end if;

      while Solution.X < Abs(B / GCD) loop
         if (C - A * Solution.X) mod B = 0 then
            Solution.Y := (C - A * Solution.X) / B;
            exit;
         end if;
         Solution.X := Solution.X + 1;
      end loop;

      if A < 0 then
         Solution.X := -Solution.X;
      end if;
      if B < 0 then
         Solution.Y := -Solution.Y;
      end if;

      Solution.XK := B / GCD;
      Solution.YK := (- A) / GCD;

      Diophantine_Format(Solution.X, Solution.Y, Solution.XK, Solution.YK);

      return Solution;
   end Diophantine_Eq_L;

   function Diophantine_Eq_R(A, B, C : Integer) return Diophantine_Solution is
      Solution : Diophantine_Solution;
      GCD : Natural;
   begin
      -- checking whether solution exists using Bezout's identity, if not then returning x = 0 and y = 0
      GCD := GCD_Extended(Abs(A), Abs(B), Solution.X, Solution.Y);
      if C mod GCD /= 0 then
         return Solution;
      end if;

      Solution.X := Solution.X * (C / GCD);
      Solution.Y := Solution.Y * (C / GCD);

      if A < 0 then
         Solution.X := -Solution.X;
      end if;
      if B < 0 then
         Solution.Y := -Solution.Y;
      end if;

      Solution.XK := B / GCD;
      Solution.YK := (- A) / GCD;

      Diophantine_Format(Solution.X, Solution.Y, Solution.XK, Solution.YK);

      return Solution;
   end Diophantine_Eq_R;

end Ada_Lib;