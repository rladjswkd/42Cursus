# include .env to use environment variables defined in it
include srcs/.env

up:
	@mkdir -p ${VOLUME_PATH}/db ${VOLUME_PATH}/wp
	@docker compose -f srcs/docker-compose.yml build
	@docker compose -f srcs/docker-compose.yml up -d

# delete line 13 after all is done.
down:
	@docker compose -f srcs/docker-compose.yml down
	@docker system prune -af
	@rm -rf ${VOLUME_PATH}

log:
	docker compose -f srcs/docker-compose.yml logs

re: down up

.PHONY: up, down, log, re
