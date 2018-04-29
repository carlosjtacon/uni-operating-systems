minishell: entrada_minishell.o minishell.o ejecutar.o
	gcc -Wall entrada_minishell.o minishell.o ejecutar.o libmemoria.c libshell.a -o minishell

entrada_minishell.o: entrada_minishell.c minishell.h
	gcc -Wall -c entrada_minishell.c -o entrada_minishell.o

minishell.o: minishell.c minishell.h ejecutar.h
	gcc -Wall -c minishell.c -o minishell.o

ejecutar.o: ejecutar.c ejecutar.h parser.h minishell.h libmemoria.h internas.h
	gcc -Wall -c ejecutar.c -o ejecutar.o
		
clean:
	rm -f *.o
	rm -f minishell
	rm -f minishell.tar.gz

pack: clean
	tar zcvf minishell.tar.gz *