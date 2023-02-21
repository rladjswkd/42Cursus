<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', getenv($MYSQL_DATABASE) );

/** Database username */
define( 'DB_USER', getenv($MYSQL_USER) );

/** Database password */
define( 'DB_PASSWORD', getenv($MYSQL_PASSWORD) );

/** Database hostname */
define( 'DB_HOST', 'localhost' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'q/7ED4-:$p`|h[K,|<HL?<-9H1f2a,w3DKOnP4fT5]^dkV%Z^n,a{bn)r?^Hf^HP');
define('SECURE_AUTH_KEY',  '~5.|A8t,$h>@/qyG$/<8|uE>Nh!cj]%wk<-}O`Nv~|TZrt!CkQ+%lkdqG0WDTsN[');
define('LOGGED_IN_KEY',    '(.S/_@DM(qn+66O1oExKul#FqLPEQNBwSz9pj+oDG2xC,%$vbzgwG?y2z*?YOR;k');
define('NONCE_KEY',        '*d)HM3d/m;e3#_Dys9jvr:5Lo-te^-NnG=QI~I^?=)+Ylbq;PZrcAWo~UmVX++x]');
define('AUTH_SALT',        '}q602jM_H)jR2arK$e7bvhX+BXxU!jptJMng.M8KC>*0G;CUX<$$XT#ay{x?G{fE');
define('SECURE_AUTH_SALT', 'EEYf(8oFZR+KJ~3E[LLlcJ(amjYw-t*R}J#hJ%m:< (3%$[X0dmk8HN6eh#K%o8s');
define('LOGGED_IN_SALT',   'gKM6{%:^ zJMLFR`hN*H>4lkj){P2/qt8cK0|A}2CFzczjs:-+P!f_|ae^-7?nju');
define('NONCE_SALT',       '5RI`-[*]!`)2JL/Bx:H3,t-orqqv1FUcsU.-dYFsF-(UuO,=LnTqIskRwhF]Y<Lh');

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
