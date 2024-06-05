package body Fork is
    protected body Fork_Type is
        entry Pick_Up when not Is_Used is
        begin
            Is_Used := True;
        end Pick_Up;

        procedure Put_Down is
        begin
            Is_Used := False;
        end Put_Down;
    end Fork_Type;
end Fork;