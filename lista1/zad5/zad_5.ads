with Interfaces.C;

package Zad_5 is
    type Diophantine_Solution is record
        X : Interfaces.C.int;
        Y : Interfaces.C.int;
        XK : Interfaces.C.int;
        YK : Interfaces.C.int;
    end record;

    function wrapped_factorial_l(N : Interfaces.C.unsigned) return Interfaces.C.unsigned_long;
	pragma Import (C, wrapped_factorial_l, "factorialL");
    
    function wrapped_factorial_r(N : Interfaces.C.unsigned) return Interfaces.C.unsigned_long;
	pragma Import (C, wrapped_factorial_r, "factorialR");
	
	function wrapped_GCD_l(A, B : Interfaces.C.int) return Interfaces.C.int;
	pragma Import (C, wrapped_GCD_l, "gcdL");

    function wrapped_GCD_r(A, B : Interfaces.C.int) return Interfaces.C.int;
	pragma Import (C, wrapped_GCD_r, "gcdR");
	
	function wrapped_diophantine_eq_l(A, B, C : Interfaces.C.int) return Diophantine_Solution;
	pragma Import (C, wrapped_diophantine_eq_l, "diophantineEqL");
    	
	function wrapped_diophantine_eq_r(A, B, C : Interfaces.C.int) return Diophantine_Solution;
	pragma Import (C, wrapped_diophantine_eq_r, "diophantineEqR");

end Zad_5;