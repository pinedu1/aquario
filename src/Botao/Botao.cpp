class Botao {
	boolean estado;
	void *rotinaOnUp = NULL;
	void *rotinaOnDown = NULL;
	void *rotinaOnClick = NULL;
	void *rotinaOnChange = NULL;

	boolean getEstado() {
	}
	void setEstado(boolean estado) {
		this.estado = estado;
		if ( *rotinaOnChange != NULL ) {
			// executa onchange
		}
	}
	void onUp(void *rotinaOnUp) {
	}
	void onDown(void *rotinaOnDown) {
	}
	void onClick(void *rotinaOnClick) {
	}
	void onChange(void *rotinaOnChange) {
	}
}
