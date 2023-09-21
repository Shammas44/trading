#ifndef WSFRAME_H
#define WSFRAME_H
#include <openssl/ssl.h>
#include "error.h"
#include "buffer.h"
#include "json.h"
#include <openssl/ssl.h>
#include <stdio.h>
#include <string.h>

int read_response_handshake(SSL *ssl);

/**
 * Read a single frame from the socket
 * @param ssl - ssl object
 * @param out_message - pointer to the message to be read
 * @return int as status code
 */
int read_single_frame(SSL *ssl, char **out_message);
#endif
