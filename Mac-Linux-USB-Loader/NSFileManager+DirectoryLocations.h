//
//  NSFileManager+DirectoryLocations.h
//
//  Created by Matt Gallagher on 06 May 2010
//
//  This software is provided 'as-is', without any express or implied
//  warranty. In no event will the authors be held liable for any damages
//  arising from the use of this software. Permission is granted to anyone to
//  use this software for any purpose, including commercial applications, and to
//  alter it and redistribute it freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//     claim that you wrote the original software. If you use this software
//     in a product, an acknowledgment in the product documentation would be
//     appreciated but is not required.
//  2. Altered source versions must be plainly marked as such, and must not be
//     misrepresented as being the original software.
//  3. This notice may not be removed or altered from any source
//     distribution.
//

#import <Foundation/Foundation.h>

//
// DirectoryLocations is a set of global methods for finding the fixed location
// directoriess.
//
@interface NSFileManager (DirectoryLocations)

/**
 * Method to tie together the steps of:
 *	1) Locate a standard directory by search path and domain mask
 *  2) Select the first path in the results
 *	3) Append a subdirectory to that path
 *	4) Create the directory and intermediate directories if needed
 *	5) Handle errors by emitting a proper NSError object
 *
 * @param searchPathDirectory The search path passed to NSSearchPathForDirectoriesInDomains
 * @param domainMask The domain mask passed to NSSearchPathForDirectoriesInDomains
 * @param appendComponent The subdirectory appended
 * @param errorOut Any error from file operations
 *
 * @return The path to the directory (if path found and exists), nil otherwise
 */
- (NSString *)findOrCreateDirectory:(NSSearchPathDirectory)searchPathDirectory
                           inDomain:(NSSearchPathDomainMask)domainMask
                appendPathComponent:(NSString *)appendComponent
                              error:(NSError **)errorOut;
/**
 * Returns the path to the Application Support directory (creating it if it doesn't
 * exist)
 *
 * @return The path to the Application Support directory
 */
- (NSString *)applicationSupportDirectory;

/**
 * Returns the path to the Caches directory (creating it if it doesn't
 * exist)
 *
 * @return The path to the Caches directory
 */
- (NSString *)cacheDirectory;

@end
