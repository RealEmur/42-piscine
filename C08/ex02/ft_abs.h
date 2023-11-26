#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(num) ({int result = num; if(num < 0) result = num*-1; result;})

#endif 