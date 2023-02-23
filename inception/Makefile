# include .env to use environment variables defined in it
include srcs/.env

up:
	@sudo mkdir -p ${VOLUME_PATH}/db ${VOLUME_PATH}/wp
	@sudo rm -rf ${VOLUME_PATH}/db/* ${VOLUME_PATH}/wp/*
	@docker compose -f srcs/docker-compose.yml build
	@docker compose -f srcs/docker-compose.yml up -d

down:
	@docker compose -f srcs/docker-compose.yml down
	@docker system prune -af
	@sudo rm -rf ${VOLUME_PATH}

log:
	docker compose -f srcs/docker-compose.yml logs

re: down up

.PHONY: up, down, log, re