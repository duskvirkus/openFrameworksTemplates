#!/bin/bash

if [ "${PG_OF_PATH}" == "" ];
then
  echo "PG_OF_PATH is undefined! Exiting."
  exit 1
fi

DIR=$(dirname "$0")
if [ "${DIR}" != "." ];
then
  echo "Please run script from the directory that it's located in! Exiting."
  exit 2
fi

TEMPLATE_DIR="${PG_OF_PATH}/scripts/templates"

for i in `ls -d */ | cut -f1 -d'/'`
do
  DEST="${TEMPLATE_DIR}/${i}"
  if [ -d "$DEST" ]; then
    echo "${DEST} already exists."

    while true; do
      read -p "Do you want to overwrite it? [y/n] " yn
      case $yn in
        [Yy]* ) cp -rf ${i} ${TEMPLATE_DIR}; break;;
        [Nn]* ) echo "Skipping"; break;;
        * ) echo "Please answer yes or no.";;
      esac
    done

  else
    cp -r ${i} ${TEMPLATE_DIR}
  fi

done

echo "Done!"