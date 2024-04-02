-- ada_lib.ads

package Ada_Lib is

   type Diophantine_Solution is record
      X  : Integer;
      Y  : Integer;
      XK : Integer;
      YK : Integer;
   end record;

   function Factorial_L(N : Positive) return Natural;

   function Factorial_R(N : Positive) return Natural;

   function GCD_L(A, B : Natural) return Natural;

   function GCD_R(A, B : Natural) return Natural;

   function GCD_Extended(A, B : Natural; X, Y : out Integer) return Natural;

   procedure Diophantine_Format(X, Y, XK, YK : in out Integer);

   function Diophantine_Eq_L(A, B, C : Integer) return Diophantine_Solution;

   function Diophantine_Eq_R(A, B, C : Integer) return Diophantine_Solution;

      pragma Export (C, Factorial_L, "Factorial_L");
      pragma Export (C, Factorial_R, "Factorial_R");
      pragma Export (C, GCD_L, "GCD_L");
      pragma Export (C, GCD_R, "GCD_R");
      pragma Export (C, Diophantine_Eq_L, "Diophantine_Eq_L");
      pragma Export (C, Diophantine_Eq_R, "Diophantine_Eq_R");

end Ada_Lib;