/*
** EPITECH PROJECT, 2019
** my_putnbr.c
** File description:
** t1
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int mod;
    if (nb < 0)
    {
        my_putchar('-');
        if (nb == -2147483648) {
            my_putchar('2');
            nb = -147483648;
        }
        nb = -nb;
    }
    if (nb < 10) {
        my_putchar(nb + 48);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        mod = nb % 10;
        my_putchar(mod + 48);
    }
    return (0);
}
