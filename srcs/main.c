/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:10:23 by jbelless          #+#    #+#             */
/*   Updated: 2017/07/11 16:10:26 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "scop.h"
  
int main(){

    void *wd = mlx_init();
    void *op_wd = mlx_new_opengl_window(wd, 1000, 1000, "lala putin de ta race");

    mlx_loop(wd);

    return 0;

    free(op_wd);
}
