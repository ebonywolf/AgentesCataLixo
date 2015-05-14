#ifndef NEEDSUPDATE_H
#define NEEDSUPDATE_H


namespace pg{
class NeedsUpdate
{
	public:

		/** Default destructor */
		virtual ~NeedsUpdate()=default;
		virtual void update ( void* arg ) = 0;
	protected:
	private:
};
}
#endif // NEEDSUPDATE_H
