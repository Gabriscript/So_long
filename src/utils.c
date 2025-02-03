#include"so_long.h"

void    init_value(t_counts *count)
{
     count->p_count = 0; 
     count->c_count = 0;
     count->e_count = 0;

}

bool is_ber(char *str)
{
     int len = ft_strlen(str);
     if(str[len - 1] == 'r' || str[len - 2] == 'e' 
     || str[len - 3] == 'b' || str[len - 4] == '.')
          return(true);
     else 
          return (false);
}