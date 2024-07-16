#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    void *mlx;
    void *win;
    void *img;
    int img_width;
    int img_height;
    int width = 800;
    int height = 600;

    mlx = mlx_init();

    win = mlx_new_window(mlx, width, height, "Afficher Image XPM");

    img = mlx_xpm_file_to_image(mlx, "path/to/your/image.xpm", &img_width, &img_height);

    mlx_put_image_to_window(mlx, win, img, 0, 0);

    mlx_loop(mlx);

    return (EXIT_SUCCESS);
}
