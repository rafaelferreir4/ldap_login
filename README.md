This is a simple module to provide a bridge between Drupal and LDAP.

1. Download the adLDAP library and place si on sites/{all|sitename}/libraries: https://github.com/adldap/adLDAP/archive/v4.0.4.zip.
2. Install the module.
3. Configure the LDAP variables here: admin/config/people/ldap

###### For Developers ######
Module workflow when logging in:

1. User is on Drupal already.
1.1. User is on LDAP.
1.1.1 Update the user info based on the LDAP information and logs user in.
1.2. User is NOT on LDAP
1.2.1 Normal Drupal login

2. User is not on Drupal.
2.1 User is on LDAP
2.1.1 Creates user on Drupal and logs user in.
2.2 User is NOT on LDAP
2.2.1 Login validation error.

If you want to add additional fields to your user profile, use the hook_ldap_login_user_alter(&$drupal_user).
############################

You should be good to go :)
To test it, just try to get one username / password from the LDAP server and log in using it.

Similar modules:
Lightweight Directory Access Protocol (LDAP) (https://www.drupal.org/project/ldap) - This is a much more complex modules that will allow you read/write.