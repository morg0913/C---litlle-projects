filename1 = dynamic_vector
filename2 = singly_linked_list
filename3 = queue


gd = gcc -ansi -pedantic-errors -Wall -Wextra -g
gc = gcc -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3

all: dynamic_vector_debug dynamic_vector_release queue_debug queue_release singly_linked_list_release singly_linked_list_debug




dynamic_vector_debug: $(filename1).c test/$(filename1)_test.c include/$(filename1).h
	$(gd) -o $(filename1)_debug $(filename1).c test/$(filename1)_test.c -I include/
	
dynamic_vector_release: $(filename1).c test/$(filename1)_test.c include/$(filename1).h
	$(gc) -o $(filename1)_release $(filename1).c test/$(filename1)_test.c -I include/




singly_linked_list_release: $(filename2).c test/$(filename2)_test.c include/$(filename2).h
	$(gd) -o $(filename2)_debug $(filename2).c ./test/$(filename2)_test.c -I include/
 
singly_linked_list_debug: $(filename2).c test/$(filename2)_test.c include/$(filename2).h
		$(gc) -o $(filename2)_release $(filename2).c ./test/$(filename2)_test.c -I include/




queue_debug: $(filename3).c ./$(filename2).c test/$(filename3)_test.c include/$(filename3).h
	$(gd) -o $(filename3)_debug $(filename2).c $(filename3).c ./test/$(filename3)_test.c -I include/
 
queue_release: $(filename3).c ./$(filename2).c test/$(filename3)_test.c include/$(filename3).h
		$(gc) -o $(filename3)_release $(filename3).c $(filename2).c ./test/$(filename3)_test.c -I include/


