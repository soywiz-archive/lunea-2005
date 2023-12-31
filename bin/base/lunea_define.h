#include <lunea_debug.h>

const char *GetDataResourceFromName(const char *file, long &hResLength);
int create_file_from_resource(const char *resname, char *fname);
void delete_file_created_from_resource(char *fname);