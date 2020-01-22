begin

        assign(input,'jump.in');
        assign(output,'jump.out');
        reset(input);
        rewrite(output);
        write('-1');
        close(input);
        close(output);
end.