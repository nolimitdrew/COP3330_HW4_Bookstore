menu_executable: menu.o store.o book.o
	g++ -o menu menu.o store.o book.o
	chmod 755 menu

menu.o: menu.cpp store.h book.h
	g++ -c menu.cpp
    
store.o: store.cpp store.h book.h
	g++ -c store.cpp    
    
book.o: book.cpp book.h
	g++ -c book.cpp

clean:
	rm -f *.o



