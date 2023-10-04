#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H


#include <iostream>

class Contact {

    public:

        Contact( void );
        ~Contact( void );

        //Setters
        void setFirstName ( std::string str);
        void setLastName ( std::string str);
        void setNickname ( std::string str);
        void setPhoneNumber ( std::string str);
        void setDarkestSecret ( std::string str);


        //Getters
        std::string getFirstName ( void ) const;
        std::string getLastName ( void ) const;
        std::string getNickname ( void ) const;
        std::string getPhoneNumber ( void ) const;
        std::string getDarkestSecret ( void ) const;

        void        displayContact( void );

    private:

        std::string         _first_name;
        std::string         _last_name;
        std::string         _nickname;
        std::string         _phone_number;
        std::string         _darkest_secret;
};

#endif