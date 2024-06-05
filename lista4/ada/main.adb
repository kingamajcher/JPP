with Fork;
with Philosopher;

procedure Dining_Philosopher is
    Number_Of_Philosophers : constant := 4;
    Meal_Limit : constant := 3;

    Forks : array (1 .. Number_Of_Philosophers) of aliased Fork.Fork_Type;

    type Philosopher_Task_Pointer is access Philosopher.Philosopher_Task;
    Philosopher_Task_Pointers : array (1 .. Number_Of_Philosophers) of Philosopher_Task_Pointer;

    Lower_Fork_Index : Integer;
    Higher_Fork_Index : Integer;
    Temp : Integer;
begin
    for I in 1 .. Number_Of_Philosophers loop
        Lower_Fork_Index := I;
        Higher_Fork_Index := (I mod Number_Of_Philosophers) + 1;

        if Lower_Fork_Index > Higher_Fork_Index then
            Temp := Lower_Fork_Index;
            Lower_Fork_Index := Higher_Fork_Index;
            Higher_Fork_Index := Temp;
        end if;

        Philosopher_Task_Pointers (I) := new Philosopher.Philosopher_Task (
            I, Forks (Lower_Fork_Index)'Access, Forks (Higher_Fork_Index)'Access, Meal_Limit
        );
    end loop;

    for I in 1 .. Number_Of_Philosophers loop
        Philosopher_Task_Pointers (I).Start;
    end loop;
end Dining_Philosopher;