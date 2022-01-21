#!/bin/bash

echo `redis-cli  LPUSH First "{\"name\": \"get_spectrum\", \"id\": \"123\"}"`
echo `redis-cli LPOP 123` 