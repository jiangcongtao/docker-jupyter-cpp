ARG BASE_CONTAINER=jupyter/minimal-notebook
FROM $BASE_CONTAINER

LABEL author="Nick Jiang <congtao.jiang@outlook.com>"
USER root

RUN echo -e "jovyan\njovyan" | passwd  jovyan \
    && echo "jovyan ALL=(ALL) NOPASSWD:ALL" | sudo tee /etc/sudoers.d/jovyan \
    && conda install -y xeus-cling jupyter_contrib_nbextensions -c conda-forge 

USER $NB_UID   
# RUN pip install pandas numpy matplotlib plotly
