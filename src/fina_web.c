#include "uo_conf.h"
#include "uo_http.h"
#include "uo_http_server.h"
#include "uo_err.h"

#include <stdio.h>

int main(
    int argc, 
    char **argv)
{
    uo_http_init();

    uo_conf *conf = uo_conf_create("fina-web.conf");

    const char *port = uo_conf_get(conf, "http_server.port");
    const char *root_dir = uo_conf_get(conf, "http_server.root_dir");
    uo_http_server *http_server = uo_http_server_create(port);
    if (!uo_http_server_set_root_dir(http_server, root_dir))
        uo_err_exit("Error while setting root directory.");
    uo_http_server_start(http_server);

    printf("Press 'q' to quit...\n");
    while(getchar() != 'q');

    uo_http_server_destroy(http_server);
    uo_conf_destroy(conf);

    return 0;
}