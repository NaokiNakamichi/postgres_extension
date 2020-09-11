## forbid_truncate


This module uses a hook on utility commands to put restrictions on them.
In the particular case of this module, All users can't execute TRUNCATE TABLE .
In order to enable this module in a PostgreSQL instance, the following parameter needs to be set in postgresql.conf after installing this module:

```
    shared_preload_libraries = 'forbid_truncate'
```

test 
