#ifndef _LOG_ERROR_H
#define _LOG_ERROR_H

#include <iostream>
#include <string>

/**
 * Log an SDL error with an error message to the output stream.
 *
 * @param os  The output stream to write the message to.
 * @param msg The error message to write, with format "{msg} error: {SDL_GetError()}".
 */
void logSDLError(std::ostream& os, const std::string& msg);

/**
 * Log an SDL_image error with an error message to the output stream.
 *
 * @param os  The output stream to write the message to.
 * @param msg The error message to write, with format "{msg} error: {IMG_GetError()}".
 */
void logIMGError(std::ostream& os, const std::string& msg);

/**
 * Log an SDL_ttf error with an error message to the output stream.
 *
 * @param os  The output stream to write the message to.
 * @param msg The error message to write, with format "{msg} error: {TTF_GetError()}".
 */
void logTTFError(std::ostream& os, const std::string& msg);

/**
 * Log an SDL_mixer error with an error message to the output stream.
 *
 * @param os  The output stream to write the message to.
 * @param msg The error message to write, with format "{msg} error: {Mix_GetError()}".
 */
void logMixError(std::ostream& os, const std::string& msg);

/**
 * Log an error message to the output stream.
 *
 * @param os  The output stream to write the message to.
 * @param msg The error message to write.
 */
void logError(std::ostream& os, const std::string& msg);

#endif
