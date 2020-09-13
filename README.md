# forbid_truncate

This is released under the [PostgreSQL License](https://opensource.org/licenses/postgresql), a liberal Open Source license, similar to the BSD or MIT licenses.



## test status
[![Build Status](https://travis-ci.org/NaokiNakamichi/postgres_extension.svg?branch=master)](https://travis-ci.org/NaokiNakamichi/postgres_extension)

## overview
This module uses a hook on utility commands to put restrictions on them.
In the particular case of this module, All users can't execute TRUNCATE TABLE .
In order to enable this module in a PostgreSQL instance, the following parameter needs to be set in postgresql.conf after installing this module:

```
    shared_preload_libraries = 'forbid_truncate'
```
