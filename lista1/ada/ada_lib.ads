-- ada_lib.ads
-- Specification file

package Ada_Lib is

   -- struct for solution of diofantic equation
   type Diophantine_Solution is record
      X  : Integer;
      Y  : Integer;
      XK : Integer;
      YK : Integer;
   end record;

   -- function calculating factorial of n using loop
   function Factorial_L(N : Positive) return Natural;

   -- function calculating factorial of n using recursion
   function Factorial_R(N : Positive) return Natural;

   -- function calculating greatest common divider of a and b using loop
   function GCD_L(A, B : Natural) return Natural;

   -- function calculating greatest common divider of a and b using recursion
   function GCD_R(A, B : Natural) return Natural;

   -- function to help calculate solutions to diophantine equation
   function GCD_Extended(A, B : Natural; X, Y : out Integer) return Natural;

   -- function to format the solution of diophantine equation
   procedure Diophantine_Format(X, Y, XK, YK : in out Integer);

   -- function to calculate the solution of Diophantine equation using loop
   function Diophantine_Eq_L(A, B, C : Integer) return Diophantine_Solution;

   -- function to calculate the solution of Diophantine equation using recursion
   function Diophantine_Eq_R(A, B, C : Integer) return Diophantine_Solution;

end Ada_Lib;