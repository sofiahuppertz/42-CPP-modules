#include "../dec/ShrubberyCreationForm.class.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): AForm("ShrubberyCreationForm", 145, 137) {
    setTarget("default");
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target): AForm("ShrubberyCreationForm", 145, 137) {

    setTarget(_target);
    return ;
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other): AForm(other) {

    setTarget(other.getTarget());
    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {

    setTarget(other.getTarget());
    return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
    return ;
}

void ShrubberyCreationForm::local_execute (Bureaucrat const &executor) const
{
    std::ofstream ofs;
    std::string filename;
    
    (void)executor;
    std::cout << "🌳 ShrubberyCreationForm execute() called. 🌳" << std::endl;
    filename = getTarget() + "_shrubbery";
    ofs.open(filename.c_str(), std::ios::out | std::ios::app);
    if (ofs.is_open()) {
        ofs << "                                              -*.::.                                                " << std::endl;
        ofs << "                                       =--@.@...+ ..*%=                                              " << std::endl;
        ofs << "                                      :*%.. .-:........=% .:..                                       " << std::endl;
        ofs << "                                     .+#+..#:..+.#%=:**.@*:.#:+@                                     " << std::endl;
        ofs << "                              %=..:.-++*@-%=@#.+#--%%*-: -:....+%#-:                                 " << std::endl;
        ofs << "                             :=%%-. ..-.-*@@ +.=..@-*.-. ......  :. #.                               " << std::endl;
        ofs << "                        +. %:.%:..#-.+.==#.@@....%@+:=*:-::.=-+.    @=@:=                           " << std::endl;
        ofs << "                       @@@-:%%#=#:*-@::+*-#=@-.:@=@%@+#.@=::%@:%.+-.:#.-=+-                         " << std::endl;
        ofs << "                         = @@@@-+%:@- . .*@.:.#:.  :@@@-..- -=+.%=:#=#:@@+=.                        " << std::endl;
        ofs << "                     ++ .:*:.*@==..:...  :. .--.......-@@ .=@%#*@=@@.:=%+*                          " << std::endl;
        ofs << "                      .:%%#-:+...*.%...--.-:.+:::-*#+##+-%-#.=-..-.....-=..@  .                     " << std::endl;
        ofs << "                     :@#@=*....:-+@@:==#-@#@*@:##@.@=#=.#..:.*=-....- .#-..=.-...                   " << std::endl;
        ofs << "                    ...*:-=%.:=%#+@+:@%=.=.. .: .%#...-@+-.==#+@%+@+. .   ......                    " << std::endl;
        ofs << "                 .:#@+.*#.*+*.@%*=-@.@@.*%+@@@@+=+.+%%@#@@+@:%-#@++#-@=.-.-. . +=                   " << std::endl;
        ofs << "                 **@=...-:=-#-@:#-++-.:.:=:.**-@@@*@@@@-. .:..@.-*=%:.=++.=.=..-:..                 " << std::endl;
        ofs << "                 @@%%.#.*+..+%+%+*%%.*:::.. ..+..-@:%*. :: .:.  #@-@%@+%+-.=.-:.@.......            " << std::endl;
        ofs << "              @:..@@@*%-:-*@.@**.  :+@+%-....+.: .: .:=@@.-=*@-@. .:.-%*=+:-=%..#:......            " << std::endl;
        ofs << "            :+ -.--@%@@.@-%+..@@@*. %#+.=+=+=.+.+:.=..-  .+-....  ..  .-.+*@.*%*#.                  " << std::endl;
        ofs << "          .::-.-+%@..@%.+..%....@@@.+=@@%@@%@.-- @.-=#:..=:@::%+=:..=...%-#@..  .                   " << std::endl;
        ofs << "          @*=#+#@*@%@@--@@@@@@@. ...@%+ .:#+%-+   @@%:@#+@@%@+-%%+:*....::...*+=*                   " << std::endl;
        ofs << "          ..+::@@..=@@-.+%:@.  .+:...@@@@@: .@@-% @:@.-.-@:.=#..-+%=:.-....: . .+:%+=.              " << std::endl;
        ofs << "          #:@-*:.-  .@-+:...@.:*@#@@...#== @.:.@-@:@=@:=-#-+.-. .... . : .     ....*.:#..           " << std::endl;
        ofs << "         . -+%#@+. ::=*.#-+.+ ==..:-=.==.-#.-::.@=:*@.+# ...: .+.:..= ...*-..:..:- ...:%..          " << std::endl;
        ofs << "           . ::   ..-=@.:..::.:=@+*..@--:%@..@@:@:=.:*@@.@@-..#**=.. ... .:@=@=##*.#*+#.:.          " << std::endl;
        ofs << "             ... @*#.+#+..+-@#:@@@@%=#@+@@%@-@@+%=#  *...+#@*..:...... *...:.--:-..@%=@=@-.         " << std::endl;
        ofs << "                ..-=%:@@:==#@@@@@@..:@ . *@..-.#-==+*=*@@..-+=:@-.=...  .*-....*.@*%.+.             " << std::endl;
        ofs << "                 .@%.@*@@..% ..:*.+@#@+*%@+...@*-:.    %.@+@+@@@%*.:+=%+::..=.*=*.@%+@-             " << std::endl;
        ofs << "                - .#-+-..  -+.:+%:        .@-@@:.@     ..:@@:%-:%@%%#.@- .-....#@.%.                " << std::endl;
        ofs << "               ::=#.:*#=+%#@#.=.-.          *@.-.=  *%+%+. ..:.@-.+**%:+-:=.%=.-..                  " << std::endl;
        ofs << "                *@#:%.#=%.=@@%@.@@.    .@#:=@@:..*@@.    @@. ..@..+:%@@:@--.%.%*=@.                 " << std::endl;
        ofs << "                . .@@@-.%.%==.@-..=@@@@@%:.#@--:#.@.        .%  #=.%*@*+  * ....                    " << std::endl;
        ofs << "                  ++ .@*+.        ......    .@--+#.   :%##.#  %@%%-- -@.=.                          " << std::endl;
        ofs << "                 .........                   #--%@. #@@@:@#+- ..####@=.%%.                          " << std::endl;
        ofs << "                                            .##:=@.%%@@:=%%:@#   ..  .@....                         " << std::endl;
        ofs << "                                            .:=.-@@.    @@+...                                      " << std::endl;
        ofs << "                                             *@-+% .      .                                         " << std::endl;
        ofs << "                                            .@-*.:                                                  " << std::endl;
        ofs << "                                            .@@..-.                                                 " << std::endl;
        ofs << "                                             ==-+:@                                                 " << std::endl;
        ofs << "                                              @@  :                                                 " << std::endl;
        ofs << "                                             +%-...*                                                " << std::endl;
        ofs << "                                          ..@@.@@@.=@%=#                                            " << std::endl;
        ofs << "                                      . @...-+.-  %=@.  =.                                          " << std::endl;
        ofs << "                                          .#%... .@..*.=.                                           " << std::endl;
        ofs << "                                          ..@..    %.....-                                          " << std::endl;
        ofs << "                                                   ..  ..                                           " << std::endl;
        ofs.close();
    }
    return;
}



void ShrubberyCreationForm::local_failure( void ) const
{
    return;
}