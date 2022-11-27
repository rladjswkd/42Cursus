NAME	= 

CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
#RM		= rm -f 

SRCS	= 
OBJS	= $(SRCS:.cpp=.o)

all		: $(NAME)
$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
$(OBJS)	: $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(SRCS)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
