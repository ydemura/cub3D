//
//  header_all.h
//  cubik_xcode_part
//
//  Created by Yuliia Demura on 01/04/2021.
//

#ifndef header_all_h
#define header_all_h

#include "libft.h"
#include "parsing_header.h"
#include "algoritm.h"

#include <math.h>

typedef struct  s_player_info
{
    int x_player;
    int y_player;
    int x_player_view_direction;
    int y_player_view_direction;
    int x_camera;
    double y_camera;
}               t_player_info;

typedef struct         s_tile
{
    t_kind kind;
    int row;
    int col;
}                    t_tile;

typedef	struct 	s_map_size
{
	int len_rows;
	int len_cols;
    
    int map_error;
    int player_flag;
    t_error_handling errors_parsing;
}				t_map_size;

typedef struct  s_header_info
{
	t_error_handling errors_parsing;
    t_flags flags;
	
	char *texture_no_file;
    char *texture_so_file;
    char *texture_ea_file;
    char *texture_we_file;
    char *texture_sprite_file;
	
	int rgb_floor;
	int rgb_ceiling;
	
	int x_render_size;
	int y_render_size;
	
}               t_header_info;

typedef struct  s_game_state
{
    t_map_size   map_size;
    t_tile      *tiles;
	t_header_info head;
    t_player_info p_info;
    
}               t_game_state;

int		exam_get_next_line(int fd, char **line);

int form_gamestate(t_game_state *game_state, char *file_name);

int     count_map_size(char *file_name, t_map_size *map_size);

int     read_map(t_game_state *gstate, int fd);
int check_set_of_char(char c);
int find_if_error_is_identifier(char c, t_header_info *head);

t_tile  get_tile(const t_game_state *gstate, int row, int col);
void    set_tile(t_game_state *gstate, t_tile tile);


int     check_header(int fd, t_header_info *head);
int     check_if_string_is_map(char *str);
int     collect_resolution(t_header_info *head, char *str);
void    initiate_header_srtuct(t_header_info *head);
int     string_handler(char *str, t_header_info *head);
int 	color_check_collection(t_header_info *head, char *str);

int 	error_handling(t_error_handling err);

void    start_algoritm(t_game_state *game_state); //mlx, breaking xcode, later
void    find_distance(t_game_state *gstate);

#endif /* header_all_h */
