make
git clone https://github.com/Tripouille/printfTester
cd printfTester
make a
cd ..
git clone https://github.com/paulo-santana/ft_printf_tester
cp libftprintf.a ft_printf_tester && cd ft_printf_tester
sh test
cd ..
git clone https://github.com/AntoineBourin/printf-tester
cp libftprintf.a printf-tester && cd printf-tester
chmod 777 test.sh
./test.sh
cd ..
make fclean
rm -rf printfTester
rm -rf ft_printf_tester
rm -rf printf_tester
