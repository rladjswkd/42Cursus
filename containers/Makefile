NAME		= ftc
STDNAME		= stdc

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f 

SRCS		= algorithm.cpp tree.cpp main.cpp
OBJS		= $(SRCS:.cpp=.o)

STDSRCS		= main.cpp
STDOBJS		= $(STDSRCS:.cpp=.o)

all		: $(NAME) $(STDNAME)
$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) -D FT_VERSION=1 -o $(NAME) $(OBJS)
$(OBJS)	: $(SRCS)
	$(CXX) $(CXXFLAGS) -D FT_VERSION=1 -c $(SRCS)

$(STDNAME) : $(STDOBJS)
	$(CXX) $(CXXFLAGS) -o $(STDNAME) $(STDOBJS)
$(STDOBJS) : $(STDSRCS)
	$(CXX) $(CXXFLAGS) -c $(SRCS)

clean	:
	$(RM) $(OBJS) $(STDOBJS)

fclean	: clean
	$(RM) $(NAME) $(STDNAME)

re		: fclean all

.PHONY	: all clean fclean re
