# Grupp Makefile
# Linux som utvecklingmiljö, HT18
libs:
	@echo "COMPILING LIBRARY C FILES"
	gcc -fPIC -c ./Bibliotek_1/resistance.c -o ./Bibliotek_1/resistance.o
	gcc -fPIC -c ./Bibliotek_2/calc_power_r.c -o ./Bibliotek_2/calc_power_r.o
	gcc -fPIC -c ./Bibliotek_2/calc_power_i.c -o ./Bibliotek_2/calc_power_i.o
	gcc -fPIC -c ./Bibliotek_3/e_resistance.c -o ./Bibliotek_3/e_resistance.o

	@echo "\nCREATING DYNAMIC LIBRARIES"
	gcc -shared -fPIC -o ./Bibliotek_1/libresistance.so ./Bibliotek_1/resistance.o
	gcc -shared -fPIC -o ./Bibliotek_2/libpower.so ./Bibliotek_2/calc_power_r.o ./Bibliotek_2/calc_power_i.o
	gcc -shared -fPIC -o ./Bibliotek_3/libcomponent.so ./Bibliotek_3/e_resistance.o



all:
	@echo "COMPILING LIBRARY C FILES"
	gcc -fPIC -c ./Bibliotek_1/resistance.c -o ./Bibliotek_1/resistance.o
	gcc -fPIC -c ./Bibliotek_2/calc_power_r.c -o ./Bibliotek_2/calc_power_r.o
	gcc -fPIC -c ./Bibliotek_2/calc_power_i.c -o ./Bibliotek_2/calc_power_i.o
	gcc -fPIC -c ./Bibliotek_3/e_resistance.c -o ./Bibliotek_3/e_resistance.o

	@echo "\nCREATING DYNAMIC LIBRARIES"
	gcc -shared -fPIC -o ./lib/libresistance.so ./Bibliotek_1/resistance.o
	gcc -shared -fPIC -o ./lib/libpower.so ./Bibliotek_2/calc_power_r.o ./Bibliotek_2/calc_power_i.o
	gcc -shared -fPIC -o ./lib/libcomponent.so ./Bibliotek_3/e_resistance.o

	@echo "\nCOMPILING MAIN FILE"
	gcc -c electrotest.c
	gcc -o electrotest electrotest.o ./lib/libresistance.so ./lib/libpower.so ./lib/libcomponent.so -lm

install:
	sudo mv ./lib/libresistance.so /usr/lib/
	sudo mv ./lib/libpower.so /usr/lib/
	sudo mv ./lib/libcomponent.so /usr/lib/
	gcc -o electrotest electrotest.o /usr/lib/libresistance.so /usr/lib/libpower.so /usr/lib/libcomponent.so -lm
