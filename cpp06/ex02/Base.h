
#ifndef BASE_H
# define BASE_H

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <stdlib.h>
# include <time.h>

Base*	generate(void);

void	identify(Base* p);

void	identify(Base& p);

#endif