package Fork is
    protected type Fork_Type is
        entry Pick_Up;
        procedure Put_Down;
    private
        Is_Used : Boolean := False;
    end Fork_Type;
end Fork;